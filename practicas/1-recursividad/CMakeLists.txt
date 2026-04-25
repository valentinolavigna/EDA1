project(Recursividad)

enable_testing()

add_library(recursividad recursividad.c ruta_mina.c)

# Copiar los archivos de datos
file(GLOB DATA_FILES "archivos/*.txt")
foreach (DATA_FILE ${DATA_FILES})
    get_filename_component(FILE_NAME ${DATA_FILE} NAME)
    configure_file(${DATA_FILE} archivos/${FILE_NAME} COPYONLY)
endforeach ()

# Buscar todos los archivos de prueba que comiencen con "test_" en la carpeta "tests"
file(GLOB TEST_SOURCES "tests/test_*.c")

foreach (TEST_SOURCE ${TEST_SOURCES})
    # Extraer el nombre del archivo de prueba (sin extensión)
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)

    # Agregar un ejecutable para cada archivo de prueba encontrado
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} recursividad aserciones cadenas m)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach ()
