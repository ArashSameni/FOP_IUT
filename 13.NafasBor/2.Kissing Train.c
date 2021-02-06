#include <stdio.h>

long abs(long num)
{
	if (num < 0)
		return num * -1;
	return num;
}

int main()
{
	long k, pos[2] = {};
	scanf("%li %li %li", &k, &pos[0], &pos[1]);
	long time = 0;
	long len = abs(pos[0] - pos[1]);
	if (len < k && pos[0]/k == pos[1]/k && pos[0] * pos[1] > 0)
	{
		long temp = k - len + 1;
		if (temp < len)
			printf("%li", temp);
		else
			printf("%li", len);
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			int mood = pos[i] % k;
			int absmood = abs(mood);
			if (mood != 0)
			{
				if (k - absmood == absmood)
				{
					time += absmood;
					if (pos[1-i] > pos[i])
						pos[i] += absmood;
					else
						pos[i] -= absmood;
				}
				else if (absmood < k - absmood)
				{
					time += absmood;
					pos[i] -= mood;
				}
				else
				{
					time += k - absmood;
					if (mood < 0)
						pos[i] = pos[i] - (k + mood);
					else
						pos[i] = pos[i] + (k - mood);
				}
			}
		}
		int temp = abs((int)(abs(pos[0] - pos[1]) / k));
		time += temp;
		if (pos[1] > pos[0])
			pos[0] += temp * k;
		else if (pos[0] > pos[1])
			pos[1] += temp * k;
		time += abs(pos[0] - pos[1]);
		printf("%li", time);
	}
	return 0;
}
