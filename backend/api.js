// api.js

const express = require('express');
const pool = require('./database.js'); // Assuming db.js is in the same directory

const router = express.Router();

router.get('/sensor-data', async (req, res) => {
  try {
    const { sensorName } = req.query;

    let query;
    let queryParams;

    if (sensorName) {
      query = 'SELECT * FROM sensor_data WHERE sensor_name = $1';
      queryParams = [sensorName];
    } else {
      query = 'SELECT * FROM sensor_data';
      queryParams = [];
    }

    const result = await pool.query(query, queryParams);
    res.json(result.rows);
  } catch (error) {
    console.error('Error fetching data from TimescaleDB:', error);
    res.status(500).json({ error: 'Internal Server Error' });
  }
});

module.exports = router;