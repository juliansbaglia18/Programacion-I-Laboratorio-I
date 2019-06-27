//Debemos lograr mostrar un mensaje al presionar el botón  'MOSTRAR'.
function Mostrar() {
    var mesDelAnio;

    mesDelAnio = prompt("ingrese el mes del año.");
    mesDelAnio = mesDelAnio.toLocaleLowerCase();
    if (mesDelAnio == "enero" || mesDelAnio == "febrero" || mesDelAnio == "marzo" || mesDelAnio == "abril" || mesDelAnio == "mayo" || mesDelAnio == "junio" || mesDelAnio == "julio" || mesDelAnio == "agosto" || mesDelAnio == "septiembre" || mesDelAnio == "octubre" || mesDelAnio == "noviembre" || mesDelAnio == "diciembre") {
        switch (mesDelAnio) {
            case ("enero"):
            case ("febrero"):
                alert("Veranito!!");
                break;
            case ("marzo"):
            case ("abril"):
            case ("mayo"):
            case ("junio"):
            case ("julio"):
            case ("agosto"):
            case ("septiembre"):
            case ("octubre"):
            case ("noviembre"):
            case ("diciembre"):
                alert("Extraño el veranito");
                break;
        }
    }
    else {
        alert("Error. Dato invalido.")
    }
}





