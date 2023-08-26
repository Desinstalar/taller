package nomina;
import java.util.Scanner;

public class trabajo2 {
    public static void main(String[] args) {
        
        Thread hiloReproduccion = new Thread(new ReproduccionCancion());
        hiloReproduccion.start();

        // Realizar una tarea por consola
        Scanner scanner = new Scanner(System.in);
        System.out.print("Por favor, ingresa tu nombre: ");
        String nombre = scanner.nextLine();
        System.out.println("Hola, " + nombre + "!");

        
        try {
            hiloReproduccion.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        scanner.close();
    }
}

class ReproduccionCancion implements Runnable {
    @Override
    public void run() {
        
        String rutaArchivoCancion = "C:\\Users\\USUARIO\\Downloads\\y2mate.com - Lost Official Music Video  Linkin Park.mp3"; 

        
        System.out.println("Reproduciendo la canción...");
        try {
            Thread.sleep(5000); 
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Canción finalizada.");
    }
}