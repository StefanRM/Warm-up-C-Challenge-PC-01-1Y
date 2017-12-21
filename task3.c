#include <stdio.h>

unsigned long long coordinateConfig(int a)
{
	int i, j, x, y;
	unsigned long long config = 1;

	y = a % 8;
	a = a >> 3;
	x = a % 8;
	for (i = 0; i < 7 - x; i++) {
		config = config << 8;	// sarim un rand
	}
	config = config << (7 - y);
	return config;
}

int soldierExists(unsigned long long mask, unsigned long long mapConfig)
{
	if (mask & mapConfig) {
		return 1;
	} else {
		return 0;
	}
}

int main()
{
	unsigned long long mapConfig, config1, config2, config;
	int N, move;

	scanf("%llu", &mapConfig);
	scanf("%d", &N);
	while (N > 0) {
		scanf("%d", &move);
		config1 = coordinateConfig(move);
		move = move >> 6;
		config2 = coordinateConfig(move);
		if ((config1 != config2)
		    && (soldierExists(config1, mapConfig))) {
			config = config1 + config2;
			mapConfig = mapConfig ^ config;
		}
		N = N - 1;
	}
	printf("%llu", mapConfig);
	return 0;
}
