bool is_visible(uintptr_t mesh, float tolerance = 0.06f) {
	double Seconds = read<double>(cache::uworld + 0x190);
	float LastRenderTime = read<float>(mesh + 0x32C);
	return Seconds - LastRenderTime <= tolerance;
}

