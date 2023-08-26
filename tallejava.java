package nomina;

/**
 *
 * @author USUARIO
 */
public class trabajo {
    


    public static void main(String[] args) {
        Estudiante estudiante = new Estudiante("Carlos", 0313);
        Profesor profesor = new Profesor("Ana", "Ingles");
        Curso curso = new Curso("Gastronomia");
        CursoAcreditado cursoAcreditado = new CursoAcreditado("Calculo");

        System.out.println("Estudiante: " + estudiante.getNombre() + ", Matrícula: " + estudiante.getNumeroMatricula());
        System.out.println("Profesor: " + profesor.getNombre() + ", Especialidad: " + profesor.getEspecialidad());
        System.out.println("Curso: " + curso.getNombre());
        System.out.println("Curso acreditado: " + cursoAcreditado.getNombre());

        cursoAcreditado.verificarAcreditacion();
    }
}

class Persona {
    private String nombre;

    public Persona(String nombre) {
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}

class Curso {
    private String nombre;

    public Curso(String nombre) {
        this.nombre = nombre;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}

interface Acreditado {
    void verificarAcreditacion();
}

class Estudiante extends Persona {
    private int numeroMatricula;

    public Estudiante(String nombre, int numeroMatricula) {
        super(nombre);
        this.numeroMatricula = numeroMatricula;
    }

    public int getNumeroMatricula() {
        return numeroMatricula;
    }

    public void setNumeroMatricula(int numeroMatricula) {
        this.numeroMatricula = numeroMatricula;
    }
}

class Profesor extends Persona {
    private String especialidad;

    public Profesor(String nombre, String especialidad) {
        super(nombre);
        this.especialidad = especialidad;
    }

    public String getEspecialidad() {
        return especialidad;
    }

    public void setEspecialidad(String especialidad) {
        this.especialidad = especialidad;
    }
}

class CursoAcreditado extends Curso implements Acreditado {
    public CursoAcreditado(String nombre) {
        super(nombre);
    }

    @Override
    public void verificarAcreditacion() {
        System.out.println("El curso " + getNombre() + " está acreditado.");
    }
}

