//Debemos lograr mostrar un mensaje al presionar el botón  'MOSTRAR'.
function Mostrar()
{

    var largoDelTerreno;
    var anchoDelTerreno;
    var metrosDeAlambre;
    var vueltasDeAlambre = 6;
    var perimetroDelTerreno;

    largoDelTerreno = parseFloat(document.getElementById("largo").value);
    anchoDelTerreno = parseFloat(document.getElementById("ancho").value);
    perimetroDelTerreno = (largoDelTerreno * 2)+(anchoDelTerreno *2);
    metrosDeAlambre = perimetroDelTerreno * vueltasDeAlambre;

    if(isNaN(metrosDeAlambre) || metrosDeAlambre == Infinity || metrosDeAlambre < 0 ){
        alert("Datos invalidos.")
    }else{
        alert("Necesita " + metrosDeAlambre + " metros de alambre");
    }



		
}

