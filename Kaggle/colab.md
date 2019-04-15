!pip install -U -q kaggle
!mkdir -p ~/.kaggle
!echo '{"username":"bruce374","key":"43313de75c23e8c5a1b9713cc04183c0"}' > ~/.kaggle/kaggle.json
!chmod 600 ~/.kaggle/kaggle.json
!kaggle competitions download -c pubg-finish-placement-prediction



