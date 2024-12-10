bool is_visible(uintptr_t mesh)
{
	auto Seconds = read<double>(cache::uworld + 0x150);
	auto LastRenderTime = read<float>(mesh + 0x30C);
	return Seconds - LastRenderTime <= 0.06f;
}
