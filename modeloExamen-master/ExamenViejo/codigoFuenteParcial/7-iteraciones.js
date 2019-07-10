//Tomar datos y guardarlos en un array.
function Mostrar(){
    //Declaro variables.
    var notaEntrada;
    var sexoEntrada;
    var contador = 0;
    var alumnos = [];
    var sumaDeNotas = 0;
    var promedioDeNotas;
    var varonesAprobados = 0;
    var notaBaja;
    var notaMasBaja = 10;
    var sexo = 0;
    var nota = 1;
    //Comienza el loop de toma de datos.
    do{
        //Tomo la nota. Si necesito operarla, la parseo.
        notaEntrada = prompt("Ingrese la nota");
        notaEntrada = parseFloat(notaEntrada).toFixed(2);
        //Valido la nota y la vuelvo a pedir si es necesario.
        while(isNaN(notaEntrada) || notaEntrada == Infinity || notaEntrada < 0 || notaEntrada == null || notaEntrada > 10){
            alert("Nota invalida.");
            notaEntrada = prompt("Ingrese la nota");
            notaEntrada = parseFloat(notaEntrada).toFixed(2);
        }
        //tomo el sexo y lo transdormo a lowercase.
        sexoEntrada = prompt("Ingrese el sexo. F o M");
        sexoEntrada.toLocaleLowerCase();
        //valido el sexo y lo vuelvo a pedir si es necesario.
        while(sexoEntrada != "f" && sexoEntrada != "m"){
            alert("Sexo invalido.");
            sexoEntrada = prompt("Ingrese el sexo. F o M");
        }
        //escribo en el array    
        alumnos[contador] = [sexoEntrada , notaEntrada];
        contador++;
    }while( contador < 6 );
    //Calculo el promedio.
    for(let i = 0 ; i < alumnos.length ; i++ ){
        sumaDeNotas = sumaDeNotas + parseFloat(alumnos[i] [nota]);
    }
    promedioDeNotas = sumaDeNotas / alumnos.length;
    //Calculo la nota mas baja.
    for(let y = 0 ; y < alumnos.length ; y++ ){
    notaBaja = alumnos[y][nota];
        if(notaBaja < notaMasBaja){
        notaMasBaja = notaBaja;
        }
    }
    //calculo los varones aprobados
    for(let u = 0 ; u < alumnos.length ; u++){
        if(alumnos[u] [sexo] == "m" && alumnos[u] [nota] >= 6){
            varonesAprobados++;
        }
    }
    //Entrogo los valores.
    alert("El promedio es: "+promedioDeNotas.toFixed(2)+"\nLa nota mas baja es: "+notaBaja+"\nLa cantidad de varones aprobados es: "+varonesAprobados);
    //console.log(alumnos);
    //console.log(contador);
    //console.log("Promedio " +promedioDeNotas);
    //console.log("Nota baja " + notaMasBaja);
    //console.log("Varones aprobados " + varonesAprobados);
}