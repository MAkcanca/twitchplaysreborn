#include "TwitchTest.h"
#include "TwitchTestGameMode.generated.h"

UCLASS()
class TWITCHTEST_API ATwitchTestGameMode : public AGameMode
{
	GENERATED_BODY()

private:
	FRunnable *TwitchRunnable = NULL;
	FRunnableThread* TwitchThread = NULL;

public:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
};
