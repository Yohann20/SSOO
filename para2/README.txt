Para compilacion y ejecucion del programa secuencial es necesario lo siguiente:
- Librerias/Dependencias actualizadas de OpenCv 

- Para compilar paraleloOPEMP.cpp se necesita el siguiente comando en la terminal: " make " 
- Para ejecutar el programa paraleloOPEMP.cpp se necesita el siguiente comando en la terminal: 
" make run_threads imagen2.jpg imagen2_en_gris.jpg NUMERO_DE_HILOS " Se debe reemplazar "NUMERO_DE_HILOS" con un numero natural 
para limitar los hilos a utilizar para ejecutar el programa, ejemplo: make run_threads 4
- Si necesita eliminar el ejecutable puede utilizar el siguiente comando: " make clean "