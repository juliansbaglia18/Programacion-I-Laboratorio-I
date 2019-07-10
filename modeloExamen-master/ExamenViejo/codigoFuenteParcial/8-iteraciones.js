//Debemos lograr mostrar un mensaje al presionar el botón  'MOSTRAR'.
function Mostrar() {
    var cantidadDePares = 0;
    var sumaDeTodos = 0;
    var promedio;
    var numeroEntrante;
    var deseaContinuar;
    var numerosEntrados = [];
    var numeroMaximo;
    var numeroMinimo;
    var contador = 0;

    //Tomo los datos
    do{
    numeroEntrante = parseInt(prompt("Ingrese un numero positivo."))
    while(isNaN(numeroEntrante) || numeroEntrante == Infinity || numeroEntrante < 0 || numeroEntrante == null){
        numeroEntrante = parseInt(prompt("Error. Ingrese un numero valido"));
    }
    numerosEntrados[contador] = numeroEntrante;
    contador++;
    deseaContinuar = confirm("Desea continuar?");
    }while(deseaContinuar == true);
    //Calculo la cantidad de pares
    for(let i = 0 ; i < numerosEntrados.length ; i++){
        if((numerosEntrados[i] % 2) == 0){
            cantidadDePares++;
        }
    }
    //Calculo la suma de todos
    for(let i = 0 ; i < numerosEntrados.length ; i++){
        sumaDeTodos = sumaDeTodos + numerosEntrados[i];
    }
    //Calculo el promedio
    promedio = sumaDeTodos / contador;
    //Calculo el maximo
    numeroMaximo = Math.max(...numerosEntrados);
    //calculo el minimo
    numeroMinimo = Math.min(...numerosEntrados);

    console.log("Suma "+ sumaDeTodos + " Cantidad de pares "+cantidadDePares + " promedio " + promedio + "  " +numeroMaximo + "   " + numeroMinimo);

	

}

