# React + Vite + TimescaleDB

To run the backend of the project:

1. First open terminal and pull the TimescaleDB Docker Image with the command: docker pull timescale/timescaledb:latest-pg13.
2. Run the container with this command: docker run -d --name timescaledb -p 5432:5432 -e POSTGRES_PASSWORD=password timescale/timescaledb:latest-pg13. Update relevant fields like the password.
3. Connect to TimescaleDB with this command: psql -h localhost -U postgres -p 5432 -d postgres -W, the fields should match what you set up above.
4. Connect to your database with this command: psql -h localhost -U postgres -p 5432 -d [insert name of database] -W. The name of our database is telemetry.
