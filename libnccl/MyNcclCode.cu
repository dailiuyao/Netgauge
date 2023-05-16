#include "MyNcclCode.h"


extern "C" {

void MyncclSend(const void* sendbuff, size_t count, MyNcclDataType_t datatype, int peer, MyNcclComm_t mycomm, MycudaStream_t stream) {
                   ncclSend(sendbuff, count, datatype, peer, mycomm.ncclComm, stream);
}


void MyncclRecv(void* recvbuff, size_t count, MyNcclDataType_t datatype, int peer, MyNcclComm_t mycomm, MycudaStream_t stream) {
                   ncclRecv(recvbuff, count, datatype, peer, mycomm.ncclComm, stream);
}


void MyncclGetUniqueId(MyncclUniqueId Myout) {
                  ncclGetUniqueId(&(Myout.ncclId)); 
}


void MyncclCommInitRank(MyNcclComm_t mycomm, int nranks, MyncclUniqueId Myout, int myrank) {
                  ncclCommInitRank(&(mycomm.ncclComm), nranks, Myout.ncclId, myrank);
}

void MycudaStreamCreate ( MycudaStream_t* MypStream ) {
                  cudaStreamCreate (MypStream); 
}


void MycudaStreamDestroy ( MycudaStream_t MypStream_create ) {
                  cudaStreamDestroy (MypStream_create); 
}


void MyncclCommDestroy (MyNcclComm_t mycomm) {
                  ncclCommDestroy(mycomm.ncclComm);
}

void MycudaMalloc ( void** devPtr, size_t size ) {
                 cudaMalloc (devPtr, size); 
} 

void MycudaFree ( void* devPtr_free ) {
                  cudaFree (devPtr_free);
}

void MycudaStreamSynchronize ( MycudaStream_t Mystream ) {
                  cudaStreamSynchronize (Mystream);
}

void MycudaMemcpy ( void* dst, const void* src, size_t count, MycudaMemcpyKind kind ) {
                  cudaMemcpyKind cuda_kind;
                  if (kind == MycudaMemcpyHostToHost){
                                    cuda_kind = cudaMemcpyHostToHost;
                  } else if (kind == MycudaMemcpyHostToDevice) {
                                    cuda_kind = cudaMemcpyHostToDevice;
                  } else if (kind == MycudaMemcpyDeviceToHost) {
                                    cuda_kind = cudaMemcpyDeviceToHost;
                  } else if (kind == MycudaMemcpyDeviceToDevice) {
                                    cuda_kind = cudaMemcpyDeviceToDevice;
                  } else if (kind == MycudaMemcpyDefault) {
                                    cuda_kind = cudaMemcpyDefault;
                  }

                //   cudaMemcpyKind cuda_kind = static_cast<cudaMemcpyKind>(kind);

                  cudaMemcpy (dst, src, count, cuda_kind);
}

}


