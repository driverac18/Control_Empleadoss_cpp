Use dabatase empleadosdb;
INSERT INTO Empleado (nombre, puesto) VALUES 
('Juan Pérez', 'Gerente'),
('Carlos Sánchez', 'Vendedor');
/* Info: Records: 2  Duplicates: 0  Warnings: 0 */
INSERT INTO Turno (nombre, hora_inicio, hora_fin) VALUES 
('Mañana', '08:00:00', '16:00:00'),
('Tarde', '16:00:00', '24:00:00'),
('Noche', '24:00:00', '08:00:00');
/* Info: Records: 3  Duplicates: 0  Warnings: 0 */
INSERT INTO Horario (empleado_id, turno_id, fecha) VALUES 
(1, 1, '2024-07-01'),
(2, 2, '2024-07-01');
/* Info: Records: 2  Duplicates: 0  Warnings: 0 */