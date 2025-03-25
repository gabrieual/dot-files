function openModal(recipe) {
    const modal = document.getElementById('recipeModal');
    
    try {
        // Preenche os dados
        document.getElementById('modalTitle').textContent = recipe.title;
        document.getElementById('modalDifficulty').textContent = recipe.difficulty;
        document.getElementById('modalTime').textContent = recipe.time;
        document.getElementById('modalMealType').textContent = recipe.meal_type;
        
        // ingredientes
        const ingredientsList = document.getElementById('modalIngredients');
        ingredientsList.innerHTML = recipe.ingredients
            .map(ing => `<li>${ing.quantidade} de ${ing.nome}</li>`)
            .join('');
        
        // passos
        const stepsList = document.getElementById('modalSteps');
        stepsList.innerHTML = recipe.instructions
            .map(step => `<li>${step}</li>`)
            .join('');
        
        modal.classList.remove('hidden');
        document.body.style.overflow = 'hidden';
    } catch (error) {
        console.error('Erro ao preencher modal:', error);
        console.log('Dados da receita:', recipe);
    }
}

function closeModal() {
    document.getElementById('recipeModal').classList.add('hidden');
    document.body.style.overflow = 'auto';
}

// event listeners para o botão expandir
document.addEventListener('DOMContentLoaded', () => {
    const expandButtons = document.querySelectorAll('.expand-recipe-btn');
    expandButtons.forEach(button => {
        button.addEventListener('click', (e) => {
            e.preventDefault();
            try {
                const recipeData = JSON.parse(button.dataset.recipe);
                openModal(recipeData);
            } catch (error) {
                console.error('Erro ao processar dados da receita:', error);
                console.log('Dados recebidos:', button.dataset.recipe);
            }
        });
    });
}); 