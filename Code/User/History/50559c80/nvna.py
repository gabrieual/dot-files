from flask import render_template, request, jsonify
from app.blueprints.recipe import recipe_bp
from flask_login import current_user
import openai
import json
import re


# rota para a parte de geração de receitas
@recipe_bp.route('/', methods=['POST', 'GET'])
def new_recipe():
    return render_template("nova-receita/nova-receita.html")


# resposta para a receita 
@recipe_bp.route('/resposta', methods=['POST'])
def response():
    def generate_message(context):
        message = f'''Me forneça uma receita em formato JSON, apenas isso, sem nenhum comentário ou frase, com os seguintes campos: 
        'titulo', 'dificuldade', 'tempo_de_preparo', 'tipo_de_refeicao', 'ingredientes' (lista de objetos com 'nome' e 'quantidade'), 
        e 'passos' (lista de instruções numeradas).
        Ela deve servir {context["porcoes"]} pessoa(s)'''
        
        if not context['nao_informa_refeicao'] and context['refeicao']:
            message += f', será uma receita para {context["refeicao"]}'

        if not context['nao_informa_culinaria'] and context['culinaria']:
            message += f', ela deve ser da culinaria {context["culinaria"]}'

        if context['ingredientes']:
            apenas = 'use apenas esses ingredientes e nenhum outro, ' if context['apenas_ingredientes'] else 'se necessário pode usar outros ingredientes, '
            message += f', ela deve usar os seguintes ingredientes: {context["ingredientes"]}, {apenas}'

        if current_user.is_authenticated:
            restrictions = current_user.preferences['dietary_restrictions']
            skill_level = current_user.preferences['skill_level']
            
            if restrictions:
                restrictions_str = ', '.join(restrictions)
                message += f', a receita NÃO pode conter {restrictions_str}'
            
            message += f', a receita deve ser para alguém de nível {skill_level}'

        message += f', o tempo de preparo deve ser de aproximadamente {context["tempo"]} minutos'
        
        return message

    if request.method == "POST":
            data = request.get_json()
            message = generate_message(data)
            print('Prompt:\n'+message)
            
            import dotenv, os
            dotenv.load_dotenv(dotenv.find_dotenv())
            client = openai.OpenAI(api_key=os.getenv("API_KEY"))

            response = client.chat.completions.create(
                model="gpt-4o-mini",
                messages=[{"role": "user", "content": message}],
                temperature=0.7,
            )
            # para acessar a resposta corretamente na API
            response_content = response.choices[0].message.content
            # tirar "```json" do markdown para transformar em json
            cleaned_content = re.sub(r"^```json|```$", "", response_content).strip()
            print('Resposta da API:\n'+cleaned_content)
            cleaned_content = '''{
  "titulo": "Arroz Vegano com Legumes",
  "dificuldade": "Fácil",
  "tempo_de_preparo": "65 minutos",
  "tipo_de_refeicao": "Almoço",
  "ingredientes": [
    {
      "nome": "arroz",
      "quantidade": "3 xícaras"
    },
    {
      "nome": "água",
      "quantidade": "6 xícaras"
    },
    {
      "nome": "cenoura",
      "quantidade": "2 unidades"
    },
    {
      "nome": "brócolis",
      "quantidade": "200 gramas"
    },
    {
      "nome": "pimentão vermelho",
      "quantidade": "1 unidade"
    },
    {
      "nome": "cebola",
      "quantidade": "1 unidade"
    },
    {
      "nome": "alho",
      "quantidade": "3 dentes"
    },
    {
      "nome": "azeite de oliva",
      "quantidade": "2 colheres de sopa"
    },
    {
      "nome": "sal",
      "quantidade": "a gosto"
    },
    {
      "nome": "pimenta-do-reino",
      "quantidade": "a gosto"
    }
  ],
  "passos": [
    "Lave bem o arroz em água corrente e reserve.",
    "Descasque e corte a cebola e o alho em pequenos pedaços.",
    "Corte a cenoura e o pimentão em cubos pequenos.",
    "Separe os floretes do brócolis e reserve.",
    "Em uma panela grande, aqueça o azeite de oliva em fogo médio.",
    "Adicione a cebola e o alho, refogando até que fiquem dourados.",
    "Acrescente a cenoura e o pimentão, e refogue por cerca de 5 minutos.",
    "Adicione o arroz à panela e misture bem com os legumes.",
    "Despeje a água e tempere com sal e pimenta-do-reino.",
    "Quando a água começar a ferver, diminua o fogo e tampe a panela.",
    "Cozinhe por aproximadamente 15 minutos ou até que a água tenha evaporado.",
    "Adicione os floretes de brócolis e misture delicadamente.",
    "Tampe novamente e cozinhe por mais 5 minutos.",
    "Desligue o fogo e deixe a panela tampada por 10 minutos antes de servir.",
    "Sirva o arroz vegano com legumes quente."
  ]
}'''
            recipe_data = json.loads(cleaned_content) if cleaned_content else {}

            return jsonify(recipe_data)