﻿/*
* Совсем недавно завершились выборы, в которых участвовали три кандидата. Первый кандидат получил a голосов, второй кандидат получил b голосов, третий кандидат получил c голосов.
* Для каждого кандидата решите следующую задачу: сколько голосов нужно добавить данному кандидату, чтобы он победил на выборах (т. е. число голосов за данного кандидата было строго больше числа голосов за любого другого кандидата)?
*
* Обратите внимание, что для каждого кандидата необходимо решить данную задачу независимо, т. е. добавленные голоса за какого-либо кандидата не влияют на вычисления при анализе ответа для двух других кандидатов.
*
* В первой строке записано одно целое число t (1 ≤ t ≤ 10^4) — количество наборов входных данных. Далее следуют t наборов входных данных.
* Каждый набор входных данных состоит из одной строки, содержащей три целых числа a, b и c (0 ≤ a, b, c ≤ 10^9).
*
* Для каждого набора входных данных в отдельной строке выведите три числа A, B и C (A,B,C ≥ 0), разделённые пробелами — ответы на задачу для первого, второго и третьего кандидата соответственно.
*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int maxA = max(b, c);
		int maxB = max(a, c);
		int maxC = max(a, b);

		cout << max(0, maxA - a + 1) << " " << max(0, maxB - b + 1) << " " << max(0, maxC - c + 1);
	}
}