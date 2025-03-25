public class Order(){
	private double total;

	public void calcularTotal(double[] itemsPrice){
		for (price : itemsPrice){
			total += price;
		}
	}

	public void saveOrder(){
		// salva ordem no DB
	}

	public void printOrder(){
		// imprime a ordem na tela
	}
}
