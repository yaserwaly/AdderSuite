# AdderSuite

مكتبة C++ منظمة مع اختبارات وحدات وبنشماركس وتوثيق. الهدف توفير واجهة جمع قابلة للتوسيع مع بنية قابلة للاختبار والقياس وسهلة التكامل في بيئات CI.

---

## مخطط المشروع الكامل

AdderSuite  
├── AdderLib/                ← مشروع المكتبة الأساسية  
│   ├── include/  
│   │   ├── iadder.h  
│   │   ├── adder.h  
│   │   ├── adder_factory.h  
│   │   ├── adder_adapter.h  
│   │   ├── c_api.h  
│   │   ├── logger.h  
│   │   └── error.h  
│   └── src/  
│       ├── adder.cpp  
│       ├── adder_factory.cpp  
│       ├── adder_adapter.cpp  
│       ├── c_api.cpp  
│       ├── logger.cpp  
│       └── error.cpp  
│   └── AdderLib.vcxproj  
├── AdderTests/              ← مشروع الاختبارات (GoogleTest)  
│   ├── tests/  
│   │   ├── test_adder_real.cpp  
│   │   ├── test_adder_stub.cpp  
│   │   ├── test_adder_mock.cpp  
│   │   └── test_c_api.cpp  
│   └── AdderTests.vcxproj  
│   └── References: AdderLib + gtest/gmock  
├── AdderBenchmarks/         ← مشروع البنشماركس (Google Benchmark)  
│   ├── benchmarks/  
│   │   └── bench_adder.cpp  
│   └── AdderBenchmarks.vcxproj  
│   └── References: AdderLib + benchmark  
├── AdderDocs/               ← مشروع التوثيق (Doxygen)  
│   ├── docs/  
│   │   ├── Doxyfile  
│   │   └── overview.md  
│   └── AdderDocs.vcxproj  
│   └── External Tool: Doxygen  
├── .github/  
│   └── workflows/  
│       └── ci.yml          ← CI/CD  
└── README.md  


---

## نظرة عامة
**AdderSuite** تتألف من مكتبة النواة، مشروع اختبارات باستخدام GoogleTest، مشروع بنشماركس باستخدام Google Benchmark، ومشروع توثيق باستخدام Doxygen. الحل مُعدّ للعمل أساسًا على Windows لبناء مشاريع Visual C++، مع إمكانية استخدام أدوات .NET على Linux للمكونات المدعومة.

---

## بنية المستودع
- **AdderSuite.sln** — حل Visual Studio يجمع كل المشاريع.  
- **AdderLib/** — مكتبة النواة  
  - **include/** — رؤوس الواجهة: `iadder.h`, `adder.h`, `adder_factory.h`, `adder_adapter.h`, `c_api.h`, `logger.h`, `error.h`  
  - **src/** — تنفيذ: `adder.cpp`, `adder_factory.cpp`, `adder_adapter.cpp`, `c_api.cpp`, `logger.cpp`, `error.cpp`  
  - **AdderLib.vcxproj** — ملف المشروع  
- **AdderTests/** — اختبارات الوحدة (GoogleTest)  
  - **tests/** — `test_adder_real.cpp`, `test_adder_stub.cpp`, `test_adder_mock.cpp`, `test_c_api.cpp`  
  - **AdderTests.vcxproj** — يعتمد على AdderLib و gtest/gmock  
- **AdderBenchmarks/** — بنشماركس (Google Benchmark)  
  - **benchmarks/** — `bench_adder.cpp`  
  - **AdderBenchmarks.vcxproj** — يعتمد على AdderLib و benchmark  
- **AdderDocs/** — توثيق Doxygen  
  - **docs/** — `Doxyfile`, `overview.md`  
- **.github/workflows/** — ملفات CI مثل `ci.yml`  
- **.gitignore** — قواعد تجاهل الملفات المؤقتة ومخرجات البناء  
- **README.md** — هذا الملف

---

## كيفية البناء
### على Windows باستخدام Visual Studio
مناسب لمشاريع Visual C++ (.vcxproj):

```bash
# من سطر الأوامر
msbuild AdderSuite.sln /t:Build /p:Configuration=Release

