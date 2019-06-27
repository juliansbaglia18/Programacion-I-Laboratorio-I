//Debemos lograr mostrar un mensaje al presionar el botón  'MOSTRAR'.
function Mostrar()
{
	
    var base;
    var perimetro;
    
    base = parseFloat(document.getElementById("lado").value);
    if(isNaN(base) || base == Infinity || base < 0){
        alert("Dato invalido.")
    }
    else{
        perimetro = base * 3;
        alert("El perimetro es: " + perimetro.toFixed(2));
    }



	
}

