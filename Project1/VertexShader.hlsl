struct VsOut {
	float3 color : Color;
	float4 pos : SV_Position;
};

VsOut main(float2 pos : Position, float3 color : Color )
{
	VsOut vso;
	vso.pos = float4(pos.x, pos.y, 0.0f, 1.f);
	vso.color = color;
	return vso;
}