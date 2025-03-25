from datetime import datetime
from bson import ObjectId
from typing import List

class Receita:
    def __init__(
        self,
        titulo: str,
        ingredientes: List[str],
        instrucoes: List[str],
        id_usuario: str,
        tags: List[str],
        dificuldade: str,
        tempo_preparo: int,  # em minutos
        refeicao: str,
        _id: ObjectId = None,
        data_criacao: datetime = None
    ):
        self._id = _id or ObjectId()
        self.title = titulo
        self.ingredientes = ingredientes
        self.instrucoes = instrucoes
        self.id_usuario = id_usuario
        self.tags = tags
        self.dificuldade = dificuldade
        self.tempo_preparo = tempo_preparo
        self.refeicao = refeicao
        self.data_criacao = data_criacao or datetime.utcnow()

    def to_dict(self) -> dict:
        return {
            "_id": self._id,
            "titulo": self.titulo,
            "ingredientes": self.ingredientes,
            "instrucoes": self.instrucoes,
            "id_usuario": self.id_usuario,
            "tags": self.tags,
            "dificuldade": self.dificuldade,
            "tempo_preparo": self.tempo_preparo,
            "refeicao": self.refeicao,
            "data_criacao": self.data_criacao
        }

    @classmethod
    def from_dict(cls, data: dict) -> 'Receita':
        return cls(
            _id=data.get("_id"),
            titulo=data.get("titulo"),
            ingredientes=data.get("ingredientes"),
            instrucoes=data.get("instrucoes"),
            id_usuario=data.get("id_usuario"),
            tags=data.get("tags"),
            dificuldade=data.get("dificuldade"),
            tempo_preparo=data.get("tempo_preparo"),
            refeicao=data.get("refeicao"),
            data_criacao=data.get("data_criacao")
        )