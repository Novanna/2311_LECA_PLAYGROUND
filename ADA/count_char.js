function countFrequency(sentence) {
  // Buatlah array untuk menyimpan frekuensi huruf
  const frequency = {};

  // Looping melalui setiap huruf di kalimat
  for (const letter of sentence) {
    // Jika huruf belum ada di array, tambahkan huruf tersebut dengan frekuensi 1
    if (!frequency.hasOwnProperty(letter)) {
      frequency[letter] = 1;
    } else {
      // Jika huruf sudah ada di array, increment frekuensinya
      frequency[letter]++;
    }
  }

  // Kembalikan array frekuensi
  return frequency;
}

function sortByFrequency(frequency) {
  // Buatlah array baru untuk menyimpan hasil pengurutan
  const sortedFrequency = [];

  // Looping melalui array frekuensi
  for (const [letter, count] of Object.entries(frequency)) {
    // Tambahkan huruf dan frekuensinya ke array baru
    sortedFrequency.push([letter, count]);
  }

  // Urutkan array baru berdasarkan frekuensi
  sortedFrequency.sort((a, b) => a[1] - b[1]);

  // Kembalikan array baru yang telah diurutkan
  return sortedFrequency;
}

// Contoh penggunaan
const frequency = countFrequency("EXPLORE THE SANDBOX METAVERSE");
const sortedFrequency = sortByFrequency(frequency);

// Mencetak frekuensi huruf yang telah diurutkan
console.log(sortedFrequency);
