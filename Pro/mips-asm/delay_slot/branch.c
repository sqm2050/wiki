delay_test(int a0, int a1, int a2, int a3)
{
	a0 = 0x1111;
	a1 = 0x2222;
	a3 = a0 + a1;
	if (a0 == 0x1111)
		a2 = 0x9999;
}
