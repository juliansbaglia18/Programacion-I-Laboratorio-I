/*8-Realizar el algoritmo que al presionar el botón "Mostrar" permita ingresar números positivos (validar que sea positivo) hasta que el usuario quiera.
Informar al terminar el ingreso por document.write:
a) la cantidad de números pares.
b) el promedio de todos los números ingresados.
c) la suma de todos los números.
d) El número máximo y el mínimo.*/
function Mostrar(){
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
    while(isNaN(numeroEntrante) || numeroEntrante == Infinity || numeroEntrante > 0 || numeroEntrante == null){
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
    numeroMaximo = Math.ceil(...numerosEntrados);
    //calculo el minimo
    numeroMinimo = Math.floor(...numerosEntrados);

    console.log("Suma "+ sumaDeTodos + " Cantidad de pares "+cantidadDePares + " promedio " + promedio + "  " +numeroMaximo + "   " + numeroMinimo);


}