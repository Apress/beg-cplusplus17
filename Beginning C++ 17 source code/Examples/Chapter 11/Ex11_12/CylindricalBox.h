#include <string>
#include <string_view>

class CylindricalBox
{
public:
	static inline const float maxRadius{ 35.0f };
	static inline const float maxHeight{ 60.0f };
	static inline const std::string defaultMaterial{ "paperboard" };

	CylindricalBox(float radius, float height, std::string_view material = defaultMaterial);

	double volume() const;

private:
	// The value of PI used by CylindricalBox's volume() function
	static inline const float PI{ 3.141592f };

	double radius;
	double height;
	std::string material;
};
