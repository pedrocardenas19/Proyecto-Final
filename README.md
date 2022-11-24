# Proyecto-Final
Integrantes:
Pedro Cárdenas y Nicolas Guzman

---

## Descripción 

Nuestro proyecto es un analizador , que sirve para saber si una oracion propuesta por el usuario no tiene errores 
sintaticos , esto partiendo de una gramatica , en este caso la del español, el programa va a verificar si la oracion 
que el usuario propone no tiene estos errores , si en determinado caso los tiene el programa mostrara un mensaje de 
oracion no valida , en caso contrario debera mostrar que la oracion es valida 

---

## Videos de integrantes 

[video pedro](https://drive.google.com/file/d/1LstNgDty_BSOxnWPb8F5A_OSZpTtquyB/view?usp=drivesdk)
[video nicolas](https://drive.google.com/file/d/1e1gSGjAIGwMcyXJVZy1lnSqcqs4OjHLW/view?usp=share_linkhttps://drive.google.com/file/d/1e1gSGjAIGwMcyXJVZy1lnSqcqs4OjHLW/view?usp=share_link)

---
## Grámatica

    <oracion> -> <sujeto><predicado>
    <sujeto>  -> <enlace><determinate><sustantivo> | E
    <predicado> -> <predicadoNominal> | <predicadoVerbal>
    <predicadoNominal> -> verboCopulativo <sujeto> 
    <predicadoVerbal>  -> verbo  <sujeto> 
    <enlace> -> enlace<sujeto> | E
    <determinante> -> determinante<sujeto> | E
    <sustantivo> -> sustantivo <sujeto> | E


## Fuentes 

https://www.geeksforgeeks.org/
Analizador sintáctico. (n.d.). RecuperadoNoviembre13, 2022, from https://es.wikipedia.org/wiki/Analizador_sintáctico
Analizador sintáctico de oraciones. (2021). https://sintaxis.org/analizador/
Canarias, G. de. (2019). Sintaxis. https://libguides.cng.edu/ld.php?content_id=56777850
Español HS: Sintaxis. (n.d.). RecuperadoNoviembre13, 2022, from https://libguides.cng.edu/EspanolHS/Sintaxis
Lee, K. D. (2017). Foundations of Programming Languages(pp. 42–43). Springer International Publishing. https://doi.org/10.1007/978-3-319-70790-7






