from flask import render_template
from app.blueprints.menu import menu_bp


@menu_bp.route('/')
def menu():
    return render_template('menu/menu.html')
