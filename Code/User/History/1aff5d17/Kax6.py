import pytest
from app import create_app
import json
from unittest.mock import patch, MagicMock

@pytest.fixture
def app():
    app = create_app()
    app.config.update({
        'TESTING': True,
        'WTF_CSRF_ENABLED': False,
        'SECRET_KEY': 'test-key'
    })
    return app

@pytest.fixture
def client(app):
    return app.test_client()

def test_recipe_page_loads(client):
    """Testa se a página de geração de receita carrega"""
    response = client.get('/nova-receita/')
    assert response.status_code == 200
    assert b'nova receita' in response.data.lower()

@patch('openai.OpenAI')
def test_recipe_generation_basic(mock_openai, client):
    """Testa geração de receita com dados básicos"""
    # Mock da resposta da OpenAI
    mock_response = MagicMock()
    mock_response.choices[0].message.content = '''
    {
        "titulo": "Arroz e Feijão",
        "dificuldade": "Fácil",
        "tempo_de_preparo": "30 minutos",
        "tipo_de_refeicao": "Almoço",
        "ingredientes": [
            {"nome": "arroz", "quantidade": "2 xícaras"},
            {"nome": "feijão", "quantidade": "1 xícara"}
        ],
        "passos": [
            "Cozinhe o arroz",
            "Cozinhe o feijão"
        ]
    }
    '''
    mock_openai.return_value.chat.completions.create.return_value = mock_response

    data = {
        "ingredientes": "arroz, feijão",
        "culinaria": "brasileira",
        "porcoes": "2",
        "refeicao": "Almoço",
        "apenas_ingredientes": False,
        "tempo": "30",
        "nao_informa_refeicao": False,
        "nao_informa_culinaria": False
    }
    
    response = client.post('/nova-receita/resposta', 
                          data=json.dumps(data),
                          content_type='application/json')
    
    assert response.status_code == 200
    recipe = json.loads(response.data)
    
    # Verifica estrutura da receita
    assert recipe['titulo'] == "Arroz e Feijão"
    assert recipe['dificuldade'] == "Fácil"
    assert recipe['tempo_de_preparo'] == "30 minutos"
    assert len(recipe['ingredientes']) == 2
    assert len(recipe['passos']) == 2

def test_recipe_invalid_request(client):
    """Testa requisição com dados inválidos"""
    # Teste com JSON vazio
    response = client.post('/nova-receita/resposta', 
                          data='{}',
                          content_type='application/json')
    assert response.status_code == 500

    # Teste com dados mal formatados
    response = client.post('/nova-receita/resposta', 
                          data='invalid json',
                          content_type='application/json')
    assert response.status_code == 400

@patch('openai.OpenAI')
def test_recipe_with_dietary_restrictions(mock_openai, client):
    """Testa geração de receita considerando restrições alimentares"""
    # Mock da resposta da OpenAI
    mock_response = MagicMock()
    mock_response.choices[0].message.content = '''
    {
        "titulo": "Arroz com Legumes",
        "dificuldade": "Fácil",
        "tempo_de_preparo": "25 minutos",
        "tipo_de_refeicao": "Almoço",
        "ingredientes": [
            {"nome": "arroz", "quantidade": "2 xícaras"},
            {"nome": "cenoura", "quantidade": "1 unidade"},
            {"nome": "ervilha", "quantidade": "1/2 xícara"}
        ],
        "passos": [
            "Cozinhe o arroz",
            "Adicione os legumes"
        ]
    }
    '''
    mock_openai.return_value.chat.completions.create.return_value = mock_response

    data = {
        "ingredientes": "arroz, legumes",
        "culinaria": "vegana",
        "porcoes": "2",
        "refeicao": "Almoço",
        "apenas_ingredientes": True,
        "tempo": "25",
        "nao_informa_refeicao": False,
        "nao_informa_culinaria": False
    }
    
    response = client.post('/nova-receita/resposta', 
                          data=json.dumps(data),
                          content_type='application/json')
    
    assert response.status_code == 200
    recipe = json.loads(response.data)
    
    # Verifica se a receita é vegana
    ingredientes = [ing['nome'].lower() for ing in recipe['ingredientes']]
    assert all('carne' not in ing for ing in ingredientes)
    assert all('leite' not in ing for ing in ingredientes)
    assert all('ovo' not in ing for ing in ingredientes)

def test_recipe_message_generation():
    """Testa a geração da mensagem para a API"""
    from app.blueprints.recipe import generate_message
    
    context = {
        "ingredientes": "arroz, feijão",
        "culinaria": "brasileira",
        "porcoes": "2",
        "refeicao": "Almoço",
        "apenas_ingredientes": True,
        "tempo": "30",
        "nao_informa_refeicao": False,
        "nao_informa_culinaria": False
    }
    
    message = generate_message(context)
    
    # Verifica se a mensagem contém as informações necessárias
    assert 'JSON' in message
    assert 'titulo' in message
    assert 'ingredientes' in message
    assert 'passos' in message
    assert '2 pessoa(s)' in message
    assert 'Almoço' in message
    assert 'brasileira' in message
    assert '30 minutos' in message 