//Debemos lograr mostrar un mensaje al presionar el botón  'MOSTRAR'.
function Mostrar()
{
    var primerNumero;
    var segundoNumero;
    var resultado;

    
    do{
        primerNumero = parseFloat(prompt("Ingrese un numero"));
        if(isNaN(primerNumero) || primerNumero == Infinity){
            alert("Dato invalido.")
        }
    }while(isNaN(primerNumero) || primerNumero == Infinity)
    do{
        segundoNumero = parseFloat(prompt("Ingrese otro numero"));
        if(isNaN(segundoNumero) || segundoNumero == Infinity){
            alert("Dato invalido.")
        }
    }while(isNaN(segundoNumero) || segundoNumero == Infinity)


    if (primerNumero == segundoNumero){
        resultado = primerNumero * segundoNumero;
    }else if(primerNumero > segundoNumero){
        resultado = primerNumero - segundoNumero;
    }else{
        resultado = primerNumero + segundoNumero;
    }

    document.write(resultado);


}

