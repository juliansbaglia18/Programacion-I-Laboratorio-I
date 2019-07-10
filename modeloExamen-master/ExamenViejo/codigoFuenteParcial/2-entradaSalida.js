//Debemos lograr mostrar un mensaje al presionar el botón  'MOSTRAR'.
function Mostrar()
{
    var importeSinIva;
    var porcetanjeDeIva = 21;
    var importeFianl;

    importeSinIva = parseFloat(prompt("Ingrese el importe."));

    if(isNaN(importeSinIva) || importeSinIva == Infinity || importeSinIva < 0 ){
        alert("Dato invalido.")
    }else{
        importeFianl = importeSinIva + (importeSinIva * porcetanjeDeIva / 100);
        document.getElementById("importe").value = importeFianl.toFixed(2);
    }

}

