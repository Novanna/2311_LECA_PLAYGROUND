def knapsack_one_item(items, capacity):
    n = len(items)
    dp_table = [[0] * (capacity + 1) for _ in range(n + 1)]

    # Membuat tabel dynamic programming
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            weight = items[i - 1][2]
            value = items[i - 1][1]

            if weight <= w:
                dp_table[i][w] = max(dp_table[i - 1][w], dp_table[i - 1][w - weight] + value)
            else:
                dp_table[i][w] = dp_table[i - 1][w]

    # Mencari kombinasi yang memberikan keuntungan maksimum
    selected_items = []
    w = capacity
    for i in range(n, 0, -1):
        if dp_table[i][w] != dp_table[i - 1][w]:
            selected_items.append(items[i - 1])
            w -= items[i - 1][2]

    return dp_table, selected_items

# Barang dan nilai-nilainya
items = [('A', 45, 7),
         ('B', 35, 5),
         ('C', 25, 2),
         ('D', 40, 5),
         ('E', 55, 10),
         ('F', 35, 3),
         ('G', 75, 6)]

# Kapasitas maksimum tas
capacity = 29

# Memanggil fungsi knapsack_one_item
dp_table, selected_items = knapsack_one_item(items, capacity)

# Menampilkan hasil dalam bentuk CSV
print("Barang,Nilai,Berat")
for item in selected_items:
    print(f"{item[0]},{item[1]},{item[2]}")

print("\nTabel Dynamic Programming:")
for row in dp_table:
    print(', '.join(map(str, row)))

# Keuntungan maksimal
max_profit = dp_table[-1][-1]
print(f"\nKeuntungan Maksimal: {max_profit} Juta")

# Barang yang menjadi kombinasi
selected_items_names = [item[0] for item in selected_items]
print(f"\nBarang yang menjadi kombinasi: {', '.join(selected_items_names)}")
