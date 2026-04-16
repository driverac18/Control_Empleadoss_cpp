CREATE DATABASE IF NOT EXISTS EmpleadosDB;
USE EmpleadosDB;

CREATE TABLE Empleado (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(100) NOT NULL,
    puesto VARCHAR(100)
);

-- Tabla de turnos
CREATE TABLE Turno (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(50) NOT NULL, -- Ej: Mañana, Tarde, Noche
    hora_inicio TIME NOT NULL,
    hora_fin TIME NOT NULL
);

-- Tabla de horarios
CREATE TABLE Horario (
    id INT PRIMARY KEY AUTO_INCREMENT,
    empleado_id INT NOT NULL,
    turno_id INT NOT NULL,
    fecha DATE NOT NULL,
    FOREIGN KEY (empleado_id) REFERENCES Empleado(id),
    FOREIGN KEY (turno_id) REFERENCES Turno(id)
);

INSERT INTO Empleado (nombre, puesto) VALUES 
('Juan Pérez', 'Gerente'),
('Carlos Sánchez', 'Vendedor');

INSERT INTO Turno (nombre, hora_inicio, hora_fin) VALUES 
('Mañana', '08:00:00', '16:00:00'),
('Tarde', '16:00:00', '24:00:00'),
('Noche', '24:00:00', '08:00:00');

INSERT INTO Horario (empleado_id, turno_id, fecha) VALUES 
(1, 1, '2024-07-01'),
(2, 2, '2024-07-01');