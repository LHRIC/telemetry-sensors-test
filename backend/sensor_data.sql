CREATE TABLE sensor_data (
    id SERIAL PRIMARY KEY,
    sensor_name TEXT(255),
    rate FLOAT,
    position TEXT(255),
    channel TEXT(255),
    units TEXT(255),
    equation TEXT(255),
    offsets TEXT(255),
    time TIMESTAMPTZ DEFAULT current_timestamp NOT NULL
);

SELECT create_hypertable('sensor_data', 'time');

INSERT INTO sensor_data (sensor_name, rate, position, channel, units, equation, offsets, time)
VALUES
  ('Sensor1', 5.0, 'PositionA', 'Channel1', 'UnitsA', 'EquationA', 'OffsetA', NOW()),
  ('Sensor2', 6.5, 'PositionB', 'Channel2', 'UnitsB', 'EquationB', 'OffsetB', NOW()),
  ('Sensor3', 4.2, 'PositionC', 'Channel3', 'UnitsC', 'EquationC', 'OffsetC', NOW()),
  ('Sensor4', 7.8, 'PositionD', 'Channel4', 'UnitsD', 'EquationD', 'OffsetD', NOW());