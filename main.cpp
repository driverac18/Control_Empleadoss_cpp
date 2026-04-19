#include <iostream>
#include <vector>
#include <map>
#include "MySQLConexion.h"
#include "EloquentORM.h"
// Al final si pude correr el codigo usando mysql server 5.7 en docker 
using namespace std;

// Estructura que representa la vista combinada de Empleado + Horario + Turno
struct EmpleadoHorario {
    int id_empleado;
    string nombre;
    string puesto;
    string fecha;          
    string turno_nombre;
    string hora_inicio;
    string hora_fin;

    friend ostream& operator<<(ostream& os, const EmpleadoHorario& eh) {
        os << eh.id_empleado << " - " << eh.nombre
           << " | Puesto: " << eh.puesto
           << " | Fecha: " << eh.fecha
           << " | Turno: " << eh.turno_nombre
           << " | " << eh.hora_inicio << " - " << eh.hora_fin;
        return os;
    }
};

int main() {
    MySQLConexion conn("root", "fd18adc249", "empleadosdb");
    if (!conn.open()) {
        cerr << "Error de conexión a la base de datos" << endl;
        return 1;
    }

    vector<string> columnas; 
    EloquentORM orm(conn, "Empleado", columnas); // tabla de referencia, pero se reemplazará con raw

    // Consulta SQL con JOIN entre las tres tablas
    string consulta = R"(
        SELECT e.id, e.nombre, e.puesto,
               h.fecha,
               t.nombre AS turno_nombre,
               t.hora_inicio,
               t.hora_fin
        FROM Empleado e
        JOIN Horario h ON e.id = h.empleado_id
        JOIN Turno t ON h.turno_id = t.id
        ORDER BY e.id, h.fecha
    )";

    // Usamos raw() para establecer la consulta personalizada
    orm.raw(consulta);

    // Obtenemos los resultados
    vector< map<string, string> > resultados = orm.getAll();

    // Convertimos los mapas a nuestra estructura EmpleadoHorario
    vector<EmpleadoHorario> lista;
    for (const auto& reg : resultados) {
        EmpleadoHorario eh;
        eh.id_empleado = stoi(reg.at("id"));
        eh.nombre = reg.at("nombre");
        eh.puesto = reg.at("puesto");
        eh.fecha = reg.at("fecha");
        eh.turno_nombre = reg.at("turno_nombre");
        eh.hora_inicio = reg.at("hora_inicio");
        eh.hora_fin = reg.at("hora_fin");
        lista.push_back(eh);
    }

    for (const auto& item : lista) {
        cout << item << endl;
    }

    return 0;
}
