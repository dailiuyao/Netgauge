#include "MyNcclCode.h"


extern "C" {

ncclResult_t MyncclSend(const void* sendbuff, size_t count, MyNcclDataType_t datatype, int peer, MyNcclComm_t mycomm, MycudaStream_t stream) {
                   return ncclSend(sendbuff, count, datatype, peer, mycomm.ncclComm, stream);
}


ncclResult_t MyncclRecv(void* recvbuff, size_t count, MyNcclDataType_t datatype, int peer, MyNcclComm_t mycomm, MycudaStream_t stream) {
                   return ncclRecv(recvbuff, count, datatype, peer, mycomm.ncclComm, stream);
}


ncclResult_t MyncclGetUniqueId(MyncclUniqueId* Myout) {
                  return ncclGetUniqueId(&(Myout->ncclId)); 
}


ncclResult_t MyncclCommInitRank(MyNcclComm_t* mycomm_t, int nranks, MyncclUniqueId Myout, int myrank) {
                  return ncclCommInitRank(&(mycomm_t->ncclComm), nranks, Myout.ncclId, myrank);
}

cudaError_t MycudaStreamCreate ( MycudaStream_t* MypStream ) {
                  return cudaStreamCreate(MypStream); 
}


cudaError_t MycudaStreamDestroy ( MycudaStream_t MypStream_create ) {
                  return cudaStreamDestroy (MypStream_create); 
}


ncclResult_t MyncclCommDestroy (MyNcclComm_t mycomm) {
                  return ncclCommDestroy(mycomm.ncclComm);
}

cudaError_t MycudaMalloc ( void** devPtr, size_t size ) {
                 return cudaMalloc (devPtr, size); 
} 

cudaError_t MycudaFree ( void* devPtr_free ) {
                  return cudaFree (devPtr_free);
}

cudaError_t MycudaStreamSynchronize ( MycudaStream_t Mystream ) {
                  return cudaStreamSynchronize (Mystream);
}

cudaError_t MycudaMemcpy ( void* dst, const void* src, size_t count, MycudaMemcpyKind kind ) {
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

                  return cudaMemcpy (dst, src, count, cuda_kind);
}

uint64_t NCCL_getHostHash(const char* hostname) {
    uint64_t hash = 5381;
    int c;

    while ((c = *hostname++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}

}


