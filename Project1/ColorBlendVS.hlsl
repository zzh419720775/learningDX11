cbuffer Cbuf {
	matrix transform;
};

struct VSout {
	float4 color : Color;
	float4 pos : SV_Position

};
VSout main(float3 pos : Positon, float color : Color) : SV_POSITION
{
	VSout vso;
	vso.pos = mul(float(pos, 1.f), transform);
	vso.color = color;
	return pos;
}