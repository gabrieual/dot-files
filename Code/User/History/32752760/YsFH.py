from app.extensions import mongo
from datetime import datetime

class Recipe:
    collection = mongo.db.recipes

    @staticmethod
    def create_recipe(title:str, 
                      ingredients:list[str], 
                      instructions:list[str], 
                      difficult:str,
                      time:int,
                      meal_type:str,
                      ) -> dict:

        recipe_data = {
            "title":        title,
            "ingredients":  ingredients,
            "instructions": instructions,
            "difficult":    difficult,
            "time":         time,
            "meal_type":    meal_type,
            "create_date":  datetime.utcnow(),
            "recipe_id":    Recipe.get_next_reipe_id()
        }
        Recipe.collection.insert_one(recipe_data)
        return recipe_data

    @staticmethod
    def get_next_recipe_id() -> int:
        last_user = Recipe.collection.find_one(sort=[("recipe_id", -1)])
        return (last_user["user_id"] + 1) if last_user else 1
    
    @staticmethod
    def find_by_title(title:str):
        return list(Recipe.collection.find({"title": {"$regex": f"^{title}$", "$options": "i"}}))

    @staticmethod
    def find_by_tag(tag):
        return list(Recipe.collection.find({"tags": tag}))

    @staticmethod
    def delete_recipe(recipe_id:int):
        Recipe.collection.delete_one({"_id": recipe_id})
