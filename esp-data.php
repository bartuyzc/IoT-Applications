<!DOCTYPE html>
<html><body>
<?php
 
$servername = "sql204.infinityfree.com";
$dbname = "if0_37636652_test_db";
$username = "if0_37636652";
$password = "6046042001Bartu";
 
 
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 
 
$sql = "SELECT id, SensorData, LocationData, value1, value2, value3, reading_time FROM ESPData ORDER BY id DESC";
 
echo '<table cellspacing="5" cellpadding="5">
      <tr> 
        <td>ID</td> 
        <td>SensorData</td> 
        <td>LocationData</td> 
        <td>Value 1</td> 
        <td>Value 2</td>
        <td>Value 3</td> 
        <td>Timestamp</td> 
      </tr>';
 
if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["id"];
        $row_SensorData = $row["SensorData"];
        $row_LocationData = $row["LocationData"];
        $row_value1 = $row["value1"];
        $row_value2 = $row["value2"]; 
        $row_value3 = $row["value3"]; 
        $row_reading_time = $row["reading_time"];
        
      
        echo '<tr> 
                <td>' . $row_id . '</td> 
                <td>' . $row_SensorData . '</td> 
                <td>' . $row_LocationData . '</td> 
                <td>' . $row_value1 . '</td> 
                <td>' . $row_value2 . '</td>
                <td>' . $row_value3 . '</td> 
                <td>' . $row_reading_time . '</td> 
              </tr>';
    }
    $result->free();
}
 
$conn->close();
?> 
</table>
</body>
</html>