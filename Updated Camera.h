// USE THIS IF YOU ARE GETTING FOV FROM PLAYER CONTROLLER!
Camera get_view_point()
{
    //YOU MIGHT NEED TO UPDATE THE LOCATION AND ROTATION POINTER IN THE NEXT UPDATE SO CHECK IT OUT DONT FORGET!
    Camera view_point{};
    uintptr_t location_pointer = read<uintptr_t>(cache::uworld + 0x120); //
    uintptr_t rotation_pointer = read<uintptr_t>(cache::uworld + 0x130); //
    FNRot fnrot{};
    fnrot.a = read<double>(rotation_pointer);
    fnrot.b = read<double>(rotation_pointer + 0x20);
    fnrot.c = read<double>(rotation_pointer + 0x1D0);
    view_point.location = read<Vector3>(location_pointer);
    view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
    view_point.rotation.y = ((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1;
    auto fov_radians = read<float>(cache::player_controller + 0x3AC) * 2;
    view_point.fov * 180.0f / std::numbers::pi;
    return view_point;
}

// USE THIS IF YOU GET FOV FROM LOCALPLAYER!

Camera get_view_point()
{
	//YOU MIGHT NEED TO UPDATE THE LOCATION AND ROTATION POINTER IN THE NEXT UPDATE SO CHECK IT OUT DONT FORGET!
	Camera view_point{};
	uintptr_t location_pointer = read<uintptr_t>(cache::uworld + 0x120); //
	uintptr_t rotation_pointer = read<uintptr_t>(cache::uworld + 0x130); //
	FNRot fnrot{};
	fnrot.a = read<double>(rotation_pointer);
	fnrot.b = read<double>(rotation_pointer + 0x20);
	fnrot.c = read<double>(rotation_pointer + 0x1D0);
	view_point.location = read<Vector3>(location_pointer);
	view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
	view_point.rotation.y = ((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1;
	view_point.fov = read<float>(cache::local_player + 0x4AC); //0x3AC
	return view_point;
}


// Or use this if nothing works!

Camera get_view_point()
{
	//YOU MIGHT NEED TO UPDATE THE LOCATION AND ROTATION POINTER IN THE NEXT UPDATE SO CHECK IT OUT DONT FORGET!
	Camera view_point{};
	uintptr_t location_pointer = read<uintptr_t>(cache::uworld + 0x120); //
	uintptr_t rotation_pointer = read<uintptr_t>(cache::uworld + 0x130); //
	FNRot fnrot{};
	fnrot.a = read<double>(rotation_pointer);
	fnrot.b = read<double>(rotation_pointer + 0x20);
	fnrot.c = read<double>(rotation_pointer + 0x1D0);
	view_point.location = read<Vector3>(location_pointer);
	view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
	view_point.rotation.y = ((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1;
	view_point.fov = read<float>(cache::player_controller + 0x3AC) * 90.0f;
	return view_point;
}
