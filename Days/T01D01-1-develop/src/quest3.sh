echo mv door_management_fi door_management_files
echo cd door_management_files
echo mkdir door_configuration
echo mkdir door_map
echo mkdir door_logs
echo mv door_map_1.1 door_map
echo mv *.log door_logs
echo mv *.conf door_configuration
echo cd - 
echo chmode +x ai_door_control.sh
