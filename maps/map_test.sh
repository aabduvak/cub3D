echo "Please run me like this ./maps/map_test.sh"
echo "Following maps should all fail and exit."
echo "If the tester gets stuck, that means something is not right and the program likely does not handle that case correctly."

maps_failed=0
maps_ok=0

function_check_error () {
	if [ "$?" -ne 1 ]; then
		printf "TEST FAIL: $1\n";
		((maps_failed=maps_failed+1))
	else
		printf "TEST OK for map $1\n";
		((maps_ok=maps_ok+1))
	fi
}

./cub3D ./maps/double_identifier.cub > /dev/null 2>&1
function_check_error "Double ID"
./cub3D ./maps/double_rgb.cub > /dev/null 2>&1
function_check_error "Double RGB"
./cub3D ./maps/double_map.cub > /dev/null 2>&1
function_check_error "Double Map"
./cub3D ./maps/emptymap.cub > /dev/null 2>&1
function_check_error "Empty map"
./cub3D ./maps/invalid_symbol.cub > /dev/null 2>&1
function_check_error "invalid symbol in map"
./cub3D ./maps/invalid_texture.cub > /dev/null 2>&1
function_check_error "invalid texture"
./cub3D ./maps/multiple_player.cub > /dev/null 2>&1
function_check_error "double player"
./cub3D ./maps/non_square_tex.cub > /dev/null 2>&1
function_check_error "non square texture"
./cub3D ./maps/unknown_key.cub > /dev/null 2>&1
function_check_error "unknown direction key"
./cub3D ./maps/wrong_rgb.cub > /dev/null 2>&1
function_check_error "overflow rgb value"
./cub3D ./maps/wrong_rgb2.cub > /dev/null 2>&1
function_check_error "underflow rgb value"

FILES="./maps/invalid_maps/*"
for f in $FILES
do
  ./cub3D $f > /dev/null 2>&1
  function_check_error "$f"
done

echo "\n\nTesting of all maps finished!"
echo "Result is:"
echo "Correctly handled maps: $maps_ok"
echo "NOT correctly handled maps: $maps_failed"