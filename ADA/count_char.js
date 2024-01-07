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

// Contoh penggunaan
const sentence = "EXPLORE THE SANDBOX METAVERSE";
const frequency = countFrequency(sentence);

// Mencetak frekuensi huruf
console.log(frequency);
