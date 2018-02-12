/*-----------------------------------------------------------------------------------------------------------
This software is licensed under the Microsoft Public License (Ms-PL).
For more information about Microsoft open source licenses, refer to
http://www.microsoft.com/opensource/licenses.mspx

This license governs use of the accompanying software. If you use the software, you accept this license.
If you do not accept the license, do not use the software.

Definitions
The terms "reproduce," "reproduction," "derivative works," and "distribution" have the same meaning here
as under U.S. copyright law. A "contribution" is the original software, or any additions or changes to
the software. A "contributor" is any person that distributes its contribution under this license.
"Licensed patents" are a contributor's patent claims that read directly on its contribution.

Grant of Rights
(A) Copyright Grant- Subject to the terms of this license, including the license conditions and limitations
in section 3, each contributor grants you a non-exclusive, worldwide, royalty-free copyright license to
reproduce its contribution, prepare derivative works of its contribution, and distribute its contribution
or any derivative works that you create.

(B) Patent Grant- Subject to the terms of this license, including the license conditions and limitations in
section 3, each contributor grants you a non-exclusive, worldwide, royalty-free license under its licensed
patents to make, have made, use, sell, offer for sale, import, and/or otherwise dispose of its contribution
in the software or derivative works of the contribution in the software.

Conditions and Limitations
(A) No Trademark License- This license does not grant you rights to use any contributors' name, logo,
or trademarks.
(B) If you bring a patent claim against any contributor over patents that you claim are infringed by the
software, your patent license from such contributor to the software ends automatically.
(C) If you distribute any portion of the software, you must retain all copyright, patent, trademark, and
attribution notices that are present in the software.
(D) If you distribute any portion of the software in source code form, you may do so only under this license
by including a complete copy of this license with your distribution. If you distribute any portion of the
software in compiled or object code form, you may only do so under a license that complies with this license.
(E) The software is licensed "as-is." You bear the risk of using it. The contributors give no express warranties,
guarantees, or conditions. You may have additional consumer rights under your local laws which this license
cannot change. To the extent permitted under your local laws, the contributors exclude the implied warranties
of merchantability, fitness for a particular purpose and non-infringement.


Copyright (c) Microsoft Corporation. All rights reserved.
*/

#include "TestMain.h"
#include <math.h>

namespace cast_verify
{
	template <typename T>
	struct CastTest
	{
		T x;
		bool fExpected;
	};

	template <typename T>
	void InitializeCastArray(CastTest<T>* tests, size_t cTests)
	{
		for (unsigned long i = 0; i < cTests; ++i)
		{
			switch (i)
			{
			case 0:
				tests[i].x = static_cast<T>(pow(2, 64));
				tests[i].fExpected = false;
				break;
			case 1:
				tests[i].x = static_cast<T>(pow(2, 63));
				tests[i].fExpected = true;
				break;
			case 2:
				tests[i].x = 0;
				tests[i].fExpected = true;
				break;
			case 3:
				// This is peculiar, but (-0.0 < 0.0) == false
				tests[i].x = -0.0;
				tests[i].fExpected = true;
				break;
			case 4:
				tests[i].x = static_cast<T>(-0.01);
				tests[i].fExpected = false;
				break;
			default:
				assert(false);
				break;
			}
		}
	}

	void TestDouble()
	{
		CastTest<double> tests[5];

		InitializeCastArray(tests, _countof(tests));

		for (unsigned i = 0; i < _countof(tests); ++i)
		{
			SafeInt<unsigned __int64> test;
			bool fSuccess;

			try
			{
				test = tests[i].x;
				fSuccess = true;
			}
			catch (...)
			{
				fSuccess = false;
			}

			if(fSuccess != tests[i].fExpected)
				cerr << "Error in cast double to unsigned __int64 case " << i << endl;
		}
	}

	void TestFloat()
	{
		CastTest<float> tests[5];

		InitializeCastArray(tests, _countof(tests));

		for (unsigned i = 0; i < _countof(tests); ++i)
		{
			SafeInt<unsigned __int64> test;
			bool fSuccess;

			try
			{
				test = tests[i].x;
				fSuccess = true;
			}
			catch (...)
			{
				fSuccess = false;
			}

			if (fSuccess != tests[i].fExpected)
				cerr << "Error in cast float to unsigned __int64 case " << i << endl;
		}
	}

	void CastVerify()
	{
		cout << "Verifying Casting:" << endl;
		TestDouble();
	}
}

