float InvSqrt(float x)
{
	int i;
	float xhalf=0.5*x,y=x;
	i=*(int *) &y;     
	i=0x5f375a86 - ( i >> 1 ); 
	y=*(float *) &i;
	y=y*(1.5-(xhalf*y*y)); 
	y=y*(1.5-(xhalf*y*y));  	
	y=y*(1.5-(xhalf*y*y)); 
	return x*y;
}