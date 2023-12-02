// db.js

const { Pool } = require('pg');

const pool = new Pool({
  user: 'postgres',
  host: 'http://localhost:3001', // Replace with the IP address or domain of your TimescaleDB server
  database: 'telemetry',
  password: 'password',
  port: 5432,
});

module.exports = pool;