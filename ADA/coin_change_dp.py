def coin_change(amount, coins):
    """
    Menentukan kombinasi koin untuk membentuk jumlah uang tertentu.

    Args:
      amount: Jumlah uang yang akan dibentuk.
      coins: List koin yang tersedia.

    Returns:
      List yang berisi jumlah masing-masing koin yang dibutuhkan untuk membentuk jumlah uang tersebut.
    """

    # Buat array untuk menyimpan jumlah masing-masing koin yang dibutuhkan.
    dp = [[0] * len(coins) for _ in range(amount + 1)]

    # Isi baris pertama array dengan 0.
    for i in range(len(coins)):
        dp[0][i] = 0

    # Untuk setiap jumlah uang, pertimbangkan semua koin yang tersedia.
    for i in range(1, amount + 1):
        for j in range(len(coins)):
            # Jumlah koin yang dibutuhkan adalah jumlah koin yang dibutuhkan untuk membentuk jumlah uang yang tersisa
            # dikurangi dengan 1.
            without_this_coin = dp[i][j - 1] if j > 0 else float('inf')
            with_this_coin = dp[i - coins[j]][j] + 1 if i >= coins[j] else float('inf')
            dp[i][j] = min(with_this_coin, without_this_coin)

    return dp

def print_dp_table(dp, coins):
    # Print header
    header = ["Jumlah"] + [f"Koin {coin}" for coin in coins]
    print(', '.join(header))

    # Print table
    for i in range(len(dp)):
        row_values = [str(value) for value in dp[i]]
        print(', '.join(row_values))

# Contoh penggunaan
amount = 146
coins = [1, 5, 10, 25, 50, 100]
dp = coin_change(amount, coins)

# Print tabel dynamic programming
print_dp_table(dp, coins)
