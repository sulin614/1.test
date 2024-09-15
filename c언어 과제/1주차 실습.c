#include <stdio.h>

int main() {
	int amount;
	scanf("%d", &amount);

	int receive[100];

	for (int i = 0; i < amount; i++) {
		scanf("%d", &receive[i]);
	}
	int sell[100];

	for (int i = 0; i < amount; i++) {
		scanf("%d", &sell[i]);
	}
	int stock[100];

	for (int i = 0; i < amount; i++) {
		stock[i] = receive[i] - sell[i];
	}
	int stock_id;
	scanf("%d", &stock_id);
	printf("%d\n", stock[stock_id - 1]);

	for (int i = 0; i < amount; i++) {
		printf("%d", stock[i]);
	}
	return 0;
}