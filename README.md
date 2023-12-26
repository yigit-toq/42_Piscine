# 42 Piscine

# C00
**`norminette:`** Kodun normlara uygunluk durumunu sorgulayan yapay zeka komutudur.

**`cc - gcc:`** C dosyasını derlemek için kullanılan komutlardır.

**`./a.out:`** Standart çıktı dosyasının adı.

**`void:`** Herhangi bir değer döndürmeyen fonksiyonlar için kullanılır.

**`int:`** tam sayıları kapsayan değişkendir.  **`min -2147483648; max 2147483647`**
 - max değerin bir eksik olmasının sebebi pozitif tam sayılara 0 rakamının dahil olmasından kaynaklıdır.

**`float:`** 32 bit kapsamlı ondalıklı sayı değerlerini içerebilen değişkendir.
 - 1.5 * 10^-45 - 3.4 * 10^38

**`double:`** 64 bit kapsamlı ondalıklı sayı değerlerini içerebilen değişkendir.
 - 5.0 * 10^324 - 1.7 * 10^308

**`#include:`** Projede hazır bir kütüphane kullanmak için `header` tanımlamayı sağlayan kalıptır.

**`<unistd.h>:` `‘write’`** fonksiyonunun bulunduğu kütüphanedir.

**`<stdio.h>:` `‘printf’`** fonksiyonunun bulunduğu kütüphanedir.

**`<string.h>:` v**arsayılan C kütüphanesidir.

**`&:`** değişkenin bellek adresini işaret etmek için kullanılır.

# C01
### **`#include <stdio.h>`**

### **`printf` formatları**

1. **`%d`**: Tam sayıları (int) yazdırmak için kullanılır.
 - Örnek: **`printf("Sayı: %d\n", 42);`**
2. **`%f`**: Ondalık sayıları (float veya double) yazdırmak için kullanılır.
 - Örnek: **`printf("Ondalık Sayı: %f\n", 3.14159);`**
3. **`%c`**: Tek karakterleri yazdırmak için kullanılır.
 - Örnek: **`printf("Karakter: %c\n", 'A');`**
4. **`%s`**: Karakter dizilerini (string) yazdırmak için kullanılır.
 - Örnek: **`printf("Metin: %s\n", "Merhaba, dünya!");`**
5. **`%x`** veya **`%X`**: İşaretsiz tam sayıları onaltılı (hexadecimal) biçimde yazdırmak için kullanılır.
 - Örnek: **`printf("Hex Değer: %x\n", 255);`**
6. **`%p`**: İşaretçilerin (pointer) adresini yazdırmak için kullanılır.
 - Örnek: **`int x = 42; printf("İşaretçi Adresi: %p\n", &x);`**
7. **`%u` :** pozitif tam sayıları yazdırmak için kullanılır.
 - Örnek: **`unsigned int x = 42; printf("Pozitif Sayı: %u\n", x);`**

# C02
### **`strncpy` ve `strlcpy` arasındaki farklar**

1. Null Karakter Ekleme:
    - **`strncpy`**: Belirtilen karakter sayısı kadar kopyalama yapar, ancak hedef dizi tamamen doldurulmadan önce sonlandırıcı null karakter **`'\0'`** eklemeyebilir. Bu, hedef dizinin sonunda bir null karakterin eksik olabileceği anlamına gelir, bu da potansiyel olarak hatalı bir C string oluşturabilir.
    - **`strlcpy`**: Kaynak dizi ile hedef dizi arasındaki veriyi belirtilen karakter sayısı kadar kopyalar ve ardından hedef dizinin sonuna kesinlikle bir null karakter **`'\0'`** ekler. Bu, her zaman geçerli bir C string oluşturur.
2. Dizi Sınırı Aşımı:
    - **`strncpy`**: Hedef dizi boyutunu aşmayacak şekilde kopyalama yapar, ancak bu, kaynak dizinin boyutunu aşmasını engellemez. Eğer kaynak dizi hedef diziyi aşıyorsa, null karakter eklenmez ve hedef dizide beklenmedik sonuçlar veya bellek taşmaları olabilir.
    - **`strlcpy`**: Kaynak dizinin boyutunu aşması durumunda dizi sınırı aşımını engeller ve yalnızca belirtilen karakter sayısı kadar veriyi kopyalar.
3. Dönüş Değeri:
    - **`strncpy`**: Kopyalanan karakter sayısını döndürür. Bu, hedef dizinin sonunda null karakterin eksik olduğu durumları kontrol etmek için kullanılabilir.
    - **`strlcpy`**: Kopyalanan karakter sayısını döndürür. Bu da başarılı bir kopyalama işleminin tamamlandığını gösterir.

Genel olarak, **`strlcpy`**, karakter dizilerini güvenli bir şekilde kopyalamak için tercih edilen bir işlevidir çünkü hedef dizinin sonunda daima bir null karakter ekler ve böylece beklenmeyen sonuçları veya bellek taşmalarını önler. **`strncpy`** ise daha fazla dikkat ve ek kontrol gerektirebilir, çünkü null karakteri el ile eklemek ve dizi sınırı aşımını önlemek için ekstra adımlar gerektirebilir. Ancak, dikkatlice kullanıldığında, **`strncpy`** belirli durumlarda kullanışlı olabilir.

| Özellik | strlcpy | strncpy |
| --- | --- | --- |
| Güvenlik | Daha güvenli | Daha az güvenli |
| Verimlilik | Daha verimli | Daha az verimli |
| Yaygın kullanım | Daha yaygın olarak kullanılır | Daha az yaygın olarak kullanılır |

### **`const` nedir?**

**`const`**, C programlama dilinde kullanılan bir anahtar kelimedir ve değişkenleri veya işlev parametrelerini "değişmez" veya "sabit" olarak işaretlemek için kullanılır. 

**`const`**, bir değişkenin değerinin değiştirilemez olduğunu belirtir. Bu, bir değişkenin tanımlandığı yerden sonra yeniden atanamayacağı veya değiştirilemeyeceği anlamına gelir.

### **`printf`** fonksiyonunun girdileri

1. **`const char *format`** (Format Dizesi):
    - **`format`** parametresi, çıktının biçimini ve içeriğini tanımlayan bir dizedir. Bu bir karakter dizisidir ve genellikle çift tırnak içinde yazılır. Format dizesi içinde, yazdırılacak metin ve biçimlendirme spesifikatörleri bulunur. Örnek bir format dizesi şöyle görünebilir: **`"Merhaba, %s!"`**. Burada **`%s`**, yerine bir dize yerleştirilecek yer tutucusudur.
2. **`...`** (Daha Fazla Argüman):
    - **`printf`** fonksiyonunun sınırsız sayıda argümanı kabul edebilir. Format dizesindeki yer tutuculara karşılık gelen değerleri bu ek argümanlar sağlar. Örneğin, format dizesinde **`%s`** yer tutucusu kullanıldığında, bir veya daha fazla dize argümanı geçirilebilir.

# C03
**strncat ve strlcat arasındaki temel farklar şunlardır:**

- **`strncat`**, kaynak dizenin ilk n karakterini hedef dizeye kopyalar. strlcat ise, kaynak dizenin tüm karakterlerini hedef dizeye kopyalar, ancak hedef dizinin boyutunu aşmaması için dikkatli davranır.
- **`strncat`,** hedef dizenin sonunda null sonlandırma karakteri (null terminator) eklemek için bir argüman gerektirmez. strlcat ise, hedef dizenin sonunda null sonlandırma karakteri eklemek için bir argüman gerektirir.

**strncat'ın söz dizimi şu şekildedir:**

```c
char *strncat(char *dest, const char *src, size_t n);
```

**strncat'ın parametreleri şunlardır:**

- **`src`:** Kaynak dize.
- **`n:`** Kaynak dizenin kopyalanacak karakter sayısı.

strncat'ın dönen değeri, hedef dizenin bir gösterimidir.

**strlcat'ın söz dizimi şu şekildedir:**

```c
size_t strlcat(char *dst, const char *src, size_t size);
```

**strlcat'ın parametreleri şunlardır:**

- **`dst:`** Hedef dize.
- **`src:`** Kaynak dize.
- **`size:`** Hedef dizinin boyutu.

strlcat'ın dönen değeri, hedef dizenin uzunluğudur.

**strncat'ın bir örneği:**

```c
char dest[100] = "Hello";
char src[10] = "World";

strncat(dest, src, 5);

printf("%s\n", dest);
```

Bu örnekte, dest dizisine src dizisinin ilk 5 karakteri kopyalanır. Dest dizisinin boyutu 100 olduğundan, src dizisinin ilk 5 karakteri dest dizisinin sonuna eklenir.

**printf() fonksiyonunun çıktısı şu şekildedir:**

`HelloWorld`

**strlcat'ın bir örneği:**

```c
char dest[100] = "Hello";
char src[10] = "World";

strlcat(dest, src, sizeof(dest));

printf("%s\n", dest);
```

Bu örnekte, dest dizisine src dizisinin tüm karakterleri kopyalanır. Dest dizisinin boyutu 100 olduğundan, src dizisinin tüm karakterleri dest dizisinin sonuna eklenir.

**printf() fonksiyonunun çıktısı şu şekildedir:**

`HelloWorld`

strncat ve strlcat, C programlama dilinde sık kullanılan fonksiyonlardır. Ancak strlcat, daha güvenli bir seçenektir. Çünkü `strncat`, hedef dizenin boyutunu aşması durumunda, hedef dizinin üzerine yazma yapabilir. `strlcat` ise, hedef dizenin boyutunu aşmaması için dikkatli davranır.

**strncat ve strlcat'ın kullanımları şu şekilde özetlenebilir:**

- **`strncat`**, hedef dizenin boyutunun önemli olmadığı durumlarda kullanılabilir.
- **`strlcat`**, hedef dizenin boyutunun önemli olduğu durumlarda kullanılabilir.
- **`strlcat`**, daha güvenli bir seçenektir.

# C04
- `Recursive Fonksiyon`
    
    Kendi kendilerini çağırarak çalışırlar. Bu nedenle, değişkenlerin değerlerini tutmak için **`yığın (stack)`** yapısını kullanırlar. Yığın, bir tür bellek hiyerarşisidir ve en son eklenen veri en üstte bulunur. Özyineli fonksiyonlar, her çağrıda yığına yeni bir veri kümesi ekler ve her dönüşte yığından bir veri kümesi kaldırırlar.
    
- **`Recursive fonksiyonların çalışma prensibi:`**
    1. Fonksiyon, temel duruma ulaşıncaya kadar kendi kendini çağırır.
    2. Temel duruma ulaşıldığında, fonksiyon sonucunu döndürür.
    3. Fonksiyon, temel duruma ulaşmadan önce, yaptığı işlemleri geriye doğru yürütür.

# C05
**`Bu aşamada tek bir info var.`**
- Matematiksel fonksiyonların işleyişini biliyorsan rahatlıkla algoritmaları kurabilirsin. 😅

# C06
`argl` ve `argv` değişkenleri, programın komut satırı argümanlarını temsil eder. `argl` değişkeni, argüman sayısını tutarken, `argv` değişkeni, argümanların karakter dizilerini içeren bir dizi işaretçidir.

`argl` değişkeninin değeri, programın adı da dahil olmak üzere argüman sayısını içerir.
- Örneğin, `program1 arg1 arg2` komutuyla çalıştırılan bir program için `argl` değeri 3 olacaktır.

`argv` değişkeninin her bir öğesi, bir komut satırı argümanını temsil eder.
- Örneğin, `program1 arg1 arg2` komutuyla çalıştırılan bir program için `argv[0]`, `program1` karakter dizisini, `argv[1]`, `arg1` karakter dizisini ve `argv[2]`, `arg2` karakter dizisini gösterecektir.

# C07
### `Malloc`

- `<stdlib.h>` kütüphanesi içerisinde barınan bir fonksiyondur.
- `Malloc`, işletim sisteminden bellek tahsis eden bir fonksiyondur. `(memory allocation)`
- `Malloc`, tek bir parametre alır o da tahsis edilecek alanın boyutudur. Bu boyut, bayt cinsinden ifade edilir.
- Sorunsuz bir şekilde bellekten alan tahsis edilirse, `malloc` tahsis edilen alanın başlangıç adresini gösteren bir `pointer` döndürür. Eğer işlem başarısız gerçekleşirse `NULL` döndürür.
- `Malloc` fonksiyonu, dinamik bellek yönetimi için kullanılır. `Dinamik bellek yönetimi`, programın çalışma süresi boyunca bellek tahsis etmesine olanak tanır.

```c
void *malloc(size_t size);
```

`Malloc` fonksiyonunun iki parametresi vardır:

- `size:` Tahsis edilecek belleğin boyutu. Bu boyut, bayt cinsinden ifade edilir.
- `*void:` Tahsis edilen belleğin başlangıç adresini gösteren bir işaretçi.


# Pointer Nedir?

Tipik olarak bir bilgisayar, ayrı ayrı veya bitişik gruplar halinde idare
edilebilen ardışık olarak sayısallaştırılmış veya adreslenmiş hafıza
hücrelerinin bir dizisine sahiptir. İşaretçiler, hafızadaki bir yerin
adresini `(byte sıra numarası)` içeren bir değişkendir.

Bir veri bloğunun bellekte bulunduğu adresi içeren (gösteren) veri tipidir.

- Tanımlama biçimi: `“veri tipi” *ptr;`

- `ptr` değişkeni `“veri tipi”` ile belirtilen tipte bir verinin bellekte saklandığı adresi içerir.

- Tanımlama sonucunda bellekte `ptr` değişkeni mevcuttur. Ancak işaret ettiği veri bloğu yoktur.

1. Kullanılan herhangi bir değişkeni işaret etmek
2. Veri bloğunu boş belleği kullanarak oluşturmak

**`Pointer` değişkenin var olan bir değişkenin bulunduğu adresi göstermesi nasıl sağlanır?**

- Bu işlemi yapabilmek için var olan değişkenin adresinin bilinmesi gerekmektedir.

- `&:` Bir değişkenin adresinin belirlenmesi için kullanılır.

- `&ptr:` Belirtilen değişkenin adresini verir.

**Veri bloğunu boş belleği kullanarak oluşturmak nasıl sağlanır?**

- Bu yol sayesinde veriler için dinamik yer ayırılır. 

- Bunun için `malloc` işlevi kullanılır.

- `void *malloc(n):` Boş bellekten `n byte` yer ayırıp başlangıç adresini döndürür.

**Veriye işaretçi değişken yoluyla erişim nasıl sağlanır?**

- Bir işaretçinin gösterdiği adresteki veriye erişmek için işaretçi değişkeninin önüne * karakteri konur.

```c
int main()
{
    int i;
    int *ptr;

    ptr = &i;
    *ptr = 42;
    printf("i değişkeninin değeri %d\n", i);
    printf("ptr adresinin içeriği %d\n", *ptr);
}
```

- `Pointer` değişkenler üzerinde toplama ve çıkartma işlemleri `(++, --)` geçerlidir ve eklenecek değer tamsayı olmalıdır.

- `Pointer` değişkenin değeri 1 arttırıldığı zaman değişken bir sonraki veri bloğunu işaret eder.

- Değişkenin alacağı yeni değer işaretçi değişkenin ne tip bir veri bloğunu işaret ettiğine bağlıdır.

`int *ptr, i;`
`ptr = &i;` 

- i değişkenin adresinin 1000 olduğunu varsayalım. `ptr = 1000 (bellek adresi)`

- `ptr++;` `ptr = 1002 (bellek adresi)` ( `int` değeri işaret ettiği için)

- '(ptr + 4) = 2;' 1008 adresinin içeriğini 2 yapar.

`double *ptr, i;`

`ptr = &i;`

- i değişkenin adresinin 1000 olduğunu varsayalım. `ptr = 1000 (bellek adresi)`

- `ptr++;` `ptr = 1008 (bellek adresi)` ( `double` değeri işaret ettiği için)

'!!! Arttırma, işaret edilen veri bloğuna göre yapılır.'

Bir sonraki veri bloğunun gösterilmesi sağlanır.

`ptr++; Bir sonraki veri bloğunu gösterir.
(*ptr)++; Değişkeninin gösterdiği adresteki değeri 1 arttır.`

### Pointers and Arrays

`Pointer aritmetiği` sayesinde dizilere işaretçi değişkenler ile erişmek mümkündür.

```c
#include <stdio.h>

int main()
{
    int i[10], j;
    int *ptr;
    for (j=0; j<10; j++)
        i[j] = j;
    /* dizinin başlangıç adresine erişmek için ilk elemanın adresi kullanılabilir veya doğrudan erişim sağlanabilir */
    ptr = i;
    for (j=0; j<10; j++)
    {
        printf("%d ", ptr);
        ptr++;
    }
    printf("\n");
    /* ptr artık dizinin başını göstermez */
    ptr = i;
    for (j=0; j<10; j++)
        printf("%d ", (iptr+j));
    printf("\n");
    /* ptr hala dizinin başını gösterir */
}
```
