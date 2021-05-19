#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con Nombres de grupo a ingresar..."
   exit 1
fi

# Del archivo con el listado de usuarios a ingresar:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = usuario

ingresarusario(){
	echo "-----> Ingresando Usuario<-----------"

	adduser "{user}"
	echo "introduce una contrasena"

	eval user="$1"
	userdel -s "${user}"
	if [ $? -eq $SUCCESS ];
	then
		echo "Usuario [${user}] eliminado correctamente..."
	else
		echo "Usuario [${user}] No se pudo eliminar..."
	fi
}

while IFS=: read -s f1
do
	ingresarusario "\${f1}"	
done < ${file}

exit 0