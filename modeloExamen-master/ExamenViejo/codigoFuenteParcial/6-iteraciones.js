//Debemos lograr mostrar un mensaje al presionar el botón  'MOSTRAR'.
function Mostrar()
{
    var ventas;
    var maximo;
    var minimo;
    var contador = 1;

    while(contador <= 7){
        ventas = parseFloat(prompt("Ingrese las ventas del dia "+ contador));
        if(isNaN(ventas) || ventas == Infinity || ventas < 0){
            alert("Error. Dato invalido");
        }
        else{
            if(contador == 1){
                maximo = ventas;
                minimo = ventas;
                contador++;
            }
            else{
                if(ventas > maximo){
                    maximo = ventas;
                    contador++;
                }
                else if(ventas < minimo){
                    minimo = ventas;
                    contador++;
                }
                else{
                    contador++;
                }
            }
        }
    }
    alert("El maximo fue: " + maximo + " y el minimo: " + minimo);

	

	
}

