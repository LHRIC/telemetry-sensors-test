const { app, BrowserWindow } = require('electron')

const createWindow = () => {
    const win = new BrowserWindow({
      width: 800,
      height: 600,
      backgroundColor: '#61dafbaa',
      webPreferences: {
        nodeIntegration: true
      }
    });
  
    win.loadFile('index.html');
  }

app.whenReady().then(() => {
createWindow()
});

app.on('window-all-closed', () => {
    if (process.platform !== 'darwin') app.quit();
  });

//fetch
fetch('http://localhost:3001/api/sensor-data')
  .then(response => response.json())
  .then(data => {
    // Handle the retrieved data (e.g., update your table)
    console.log(data);
  })
  .catch(error => console.error('Error fetching data:', error));

  ``// ... (existing JavaScript code) ...

function search() {
  const searchTerm = document.getElementById('searchInput').value;

  // Fetch data from the backend
  fetch(`http://localhost:3001/api/sensor-data?sensorName=${searchTerm}`)
    .then(response => response.json())
    .then(data => {
      // Clear existing table rows
      const tableBody = document.getElementById('sensorTableBody');
      tableBody.innerHTML = '';

      // Populate the table with the retrieved data
      data.forEach(entry => {
        const row = tableBody.insertRow();
        row.insertCell(0).textContent = entry.sensor_name;
        row.insertCell(1).textContent = entry.rate;
        row.insertCell(2).textContent = entry.position;
        row.insertCell(3).textContent = entry.channel;
        row.insertCell(4).textContent = entry.units;
        row.insertCell(5).textContent = entry.equation;
        row.insertCell(6).textContent = entry.offset;
      });
    })
    .catch(error => console.error('Error fetching data:', error));
}

// ... (existing JavaScript code) ...


window.onload = () => {
  fetch('http://localhost:3001/api/sensor-data')
    .then(response => response.json())
    .then(data => {
      // Clear existing table rows
      const tableBody = document.getElementById('sensorTableBody');
      tableBody.innerHTML = '';

      // Populate the table with the retrieved data
      data.forEach(entry => {
        const row = tableBody.insertRow();
        row.insertCell(0).textContent = entry.sensor_name;
        row.insertCell(1).textContent = entry.rate;
        row.insertCell(2).textContent = entry.position;
        row.insertCell(3).textContent = entry.channel;
        row.insertCell(4).textContent = entry.units;
        row.insertCell(5).textContent = entry.equation;
        row.insertCell(6).textContent = entry.offset;
      });
    })
    .catch(error => console.error('Error fetching data:', error));
};