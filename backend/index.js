// server.js
const express = require('express');
const app = express();
const port = 3001;

// Define a simple route
app.get('/', (req, res) => {
  res.send('Hello, this is your Node.js backend!');
});

// Start the server
app.listen(port, () => {
  console.log('Server is running on port ${port}');
});

//get endpoint
app.get('/api/sensor-data', async (req, res) => {
    try {
      const query = 'SELECT * FROM sensor_data';
      const result = await client.query(query);
      res.json(result.rows);
    } catch (error) {
      console.error('Error fetching data from TimescaleDB:', error);
      res.status(500).json({ error: 'Internal Server Error' });
    }
  });

  //get endpoint (searches for sensor name)
  app.get('/api/sensor-data', async (req, res) => {
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
  
      const result = await client.query(query, queryParams);
      res.json(result.rows);
    } catch (error) {
      console.error('Error fetching data from TimescaleDB:', error);
      res.status(500).json({ error: 'Internal Server Error' });
    }
  });