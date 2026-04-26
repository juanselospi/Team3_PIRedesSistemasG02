# Proyecto: Etapa 2

## Estructura del Proyecto

La estructura principal de esta etapa se encuentra dividida en los siguientes directorios:

- **`cliente/`**: Contiene la aplicación del cliente, la cual permite a los usuarios solicitar interactivamente figuras de Lego por su nombre (ej. "Death Star II", "Millennium Falcon"). Realiza el envío de peticiones mediante Sockets.
- **`servidor/`**: Implementa el servidor de Legos (`LegoServer`). Contiene la lógica del **Sistema de Archivos** (`Filesystem`), que es responsable de organizar y recuperar la información almacenada en disco mediante el manejo de inodos y bloques.
- **`simulacion/`**: Contiene la lógica principal de simulación (`Simulation.cc`). Instancia y coordina todos los componentes, como el cliente, la red y el servidor, permitiendo probar la comunicación y el enrutamiento de manera local.
- **`Casos de prueba/`** y **`Protocolos/`**: Documentación de los protocolos de comunicación y scripts o archivos utilizados para probar la robustez y respuesta del sistema.

## Características y Funcionalidades Principales

1. **Búsqueda Insensible a Mayúsculas/Minúsculas:** El cliente soporta el ingreso de nombres de figuras de Lego sin importar la capitalización (case-insensitive), normalizando la entrada.
2. **Cierre Controlado de la Simulación:** Si el cliente ingresa la palabra `exit`, se envía una señal de apagado a todos los hilos involucrados (intermediarios, cliente y servidor) para finalizar los procesos limpiamente.
3. **Sistema de Archivos y Datos Iniciales (Seed):** El sistema almacena configuraciones de las figuras internamente usando bloques en un archivo binario. Soporta sembrar los datos iniciales de las figuras de Lego automáticamente mediante el comando `make seed`.
4. **Sistema de Bitácora (Logging):** Cada evento importante (solicitud, enrutamiento, respuesta y error) queda registrado de forma unificada en el archivo `bitacora.log`, en el formato: `[ENTIDAD] [FECHA_HORA] [TIPO_LOG] [MENSAJE]`.

## Instrucciones de Compilación y Uso

### 1. Inicializar el Sistema de Archivos

Antes de arrancar el servidor o la simulación, es necesario inicializar el disco de datos simulados y cargar las figuras de Lego por defecto. Desde la carpeta `servidor/`, ejecute:

```bash
make seed
```

### 2. Compilar los Componentes

Cada directorio (`cliente/`, `servidor/`, y `simulacion/`) cuenta con su propio archivo `Makefile`. Para compilar un componente individual, simplemente ingrese al directorio correspondiente y ejecute `make`.

### 3. Ejecutar la Simulación

Para correr el entorno completo que conecta al cliente con el servidor, diríjase al directorio `simulacion/`:

```bash
cd simulacion
make
./Simulation.out
```

- Siga las instrucciones en la terminal para interactuar con el sistema (puede buscar figuras de Lego por su nombre).
- Para finalizar correctamente y cerrar los hilos subyacentes, escriba `exit` en la consola.

### 4. Monitoreo

Durante y después de la ejecución, puede inspeccionar el archivo `bitacora.log` generado en los directorios, para validar la comunicación, el flujo de enrutamiento y diagnosticar posibles errores en la recuperación de los archivos.

### 5. Interacción Directa con el Filesystem (`fs_cli`)

Para administrar o depurar manualmente los archivos guardados en el disco simulado sin levantar el servidor, puede utilizar la herramienta de línea de comandos `fs_cli` provista en el directorio `servidor/Filesystem/`.

Primero, asegúrese de haberla compilado:

```bash
cd servidor/Filesystem
make
```

Los comandos disponibles a ejecutar son:

- **Listar archivos guardados en el disco simulado:**

```bash
./fs_cli ls
```

- **Ver el contenido de una figura/archivo alojado:**

```bash
./fs_cli cat <nombre_archivo_en_fs>
```

- **Insertar un archivo local dentro del Filesystem:**

```bash
./fs_cli put <ruta_archivo_local> <nombre_asignado_en_fs>
```

- **Eliminar un archivo del Filesystem:**

```bash
./fs_cli rm <nombre_archivo_en_fs>
```

- **Formatear el disco limpiándolo desde cero (ej. 500 bloques):**

```bash
./fs_cli format 500
```
